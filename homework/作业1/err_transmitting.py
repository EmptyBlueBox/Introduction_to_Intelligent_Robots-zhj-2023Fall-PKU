import math
import matplotlib.pyplot as plt
import numpy as np

def read_inertial_navigation(file_name):
    with open(file_name, 'r') as f:
        lines = f.readlines()
        data = [line.split() for line in lines if int(line.split()[1]) >= 71440000 and int(line.split()[1]) <= 71550000]
    return data  # ['IMU', timestamp, frame_rate, data_validity, roll, pitch, orientation]


def read_encoder(file_name):
    with open(file_name, 'r') as f:
        lines = f.readlines()
        data = [line.split() for line in lines if int(line.split()[1]) >= 71440000]
    return data  # ['E', timestamp, _, pulse_count]


def calculate_estimated_path(inertial_data, encoder_data):
    estimated_path = []
    x, y = 0, 0  # Initial position
    pulse_idx_previous = 0  # Initial pulse index
    theta_offset=float(inertial_data[0][-1])-90
    theta_previous = float(inertial_data[0][-1])  # Initial orientation

    # Iterating through the data and calculating the path
    for i in range(1, len(inertial_data)):
        # Get the orientation and distance traveled
        theta_current = float(inertial_data[i][-1])
        
        # Find the pulse index for the current timestamp
        pulse_idx_now=pulse_idx_previous
        for j in range(pulse_idx_previous, len(encoder_data)):
            if(int(encoder_data[j][1])>=int(inertial_data[i][1])):
                pulse_idx_now=j
                break
        delta_pulse = (int(encoder_data[pulse_idx_now][-1]) - int(encoder_data[pulse_idx_previous][-1])+30000)%30000
        dis_t = delta_pulse * 0.003846154  # Convert pulse to distance

        # Calculate new position based on provided equations
        x = x - dis_t * math.cos(math.radians((theta_previous + theta_current) / 2 - theta_offset))
        y = y + dis_t * math.sin(math.radians((theta_previous + theta_current) / 2 - theta_offset))
        
        # Update the path and previous orientation
        estimated_path.append((int(inertial_data[i][1]), x, y, theta_current))
        
        pulse_idx_previous = pulse_idx_now
        theta_previous = theta_current
    
    return estimated_path


def read_slam_result(file_name):
    with open(file_name, 'r') as f:
        lines = f.readlines()
        data = [line.split() for line in lines if line[0] !='t' and int(line.split()[0]) >= 71440000 and int(line.split()[0]) <= 71550000]
    return data  # [time, ang.x, ang.y, ang.z, shv.x, shv.y, shv.z]


def calculate_real_path(slam_data):
    real_path = []
    for datum in slam_data:
        time = int(datum[0])
        x = float(datum[4])
        y = float(datum[5])
        z = float(datum[6])
        real_path.append((time, x, y, z))
    return real_path

def add_iterative_noise_to_path(path, interval, noise_magnitude, N):
    """Add iterative noise to the path."""
    noisy_points = []
    
    for i, (timestamp, x, y, z) in enumerate(path):
        if (i+1) % interval == 0:
            for _ in range(N):
                noise_x = np.random.normal(0, noise_magnitude)
                noise_y = np.random.normal(0, noise_magnitude)

                noisy_x = x + noise_x
                noisy_y = y + noise_y

                noisy_points.append((timestamp, noisy_x, noisy_y, z))

                # Increase the noise magnitude for next iteration
                noise_magnitude *= 1.005  # 5% increase in noise magnitude
                N=int(N*1.005)

    return noisy_points


def plot_paths(estimated_path, real_path, interval, noise_magnitude, N):
    # Add iterative noise to the real path
    noisy_real_path = add_iterative_noise_to_path(real_path, interval, noise_magnitude, N)
    
    # Split the path into X and Y coordinates for plotting
    noisy_real_timestamp, noisy_real_x, noisy_real_y, noisy_real_z = zip(*[(d[0], d[1], d[2], d[3]) for d in noisy_real_path])
    est_timestamp, est_x, est_y, est_orientations = zip(*[(d[0], d[1], d[2], d[3]) for d in estimated_path])
    real_timestamp, real_x, real_y, real_z = zip(*[(d[0], d[1], d[2], d[3]) for d in real_path])

    
    plt.figure(figsize=(10, 10))
    plt.scatter(noisy_real_x, noisy_real_y, c='g', s=5, label='Noisy Real Path')    
    plt.plot(est_x, est_y, label='Estimated Path', color='b')
    plt.plot(real_x, real_y, label='Real Path', color='r')

    
    plt.title('Estimated Path vs. Iteratively Noisy Real Path')
    plt.xlabel('X Coordinate (m)')
    plt.ylabel('Y Coordinate (m)')
    plt.legend()
    plt.grid(True)
    plt.show()


inertial_data = read_inertial_navigation('InterSense_X_20130903_195003.txt')
encoder_data = read_encoder('COMPort_X_20130903_195003.txt')
estimated_path = calculate_estimated_path(inertial_data, encoder_data)

slam_data = read_slam_result('ld.nav')
real_path = calculate_real_path(slam_data)

plot_paths(estimated_path, real_path, 70, 0.3, 20)

print("Done")