import math

def calculate_average_distance_per_pulse(data):
    last_x, last_y, last_pulse = data[0][1], data[0][2], data[0][5]
    total_distance = 0
    total_pulse_count = 0

    for record in data:
        timestamp, x, y, yaw, speed, pulse, backdis = record

        # 计算两点之间的距离
        distance = math.sqrt((x - last_x) ** 2 + (y - last_y) ** 2)
        total_distance += distance

        # 更新脉冲计数
        if x>last_x:
            pulse_increase = pulse - last_pulse if pulse >= last_pulse else pulse + (30000 - last_pulse)
        else:
            pulse_increase = last_pulse - pulse if pulse <= last_pulse else last_pulse + (30000 - pulse)
        total_pulse_count += pulse_increase

        last_x, last_y, last_pulse = x, y, pulse
        
        print(f"total_distance: {total_distance}, total_pulse_count: {total_pulse_count}")

    # 计算平均DistancePerPulse
    if total_pulse_count != 0:
        average_distance_per_pulse = total_distance / total_pulse_count
    else:
        average_distance_per_pulse = 0

    return average_distance_per_pulse*1.96/total_distance


def read_data_from_file(file_path):
    data = []
    with open(file_path, 'r') as file:
        for line in file:
            # 假设每个值由空格分隔
            values = line.split()
            # 将字符串转换为正确的类型，例如float或int
            record = [int(values[0])] + [float(v) for v in values[1:6]] + [int(values[6])]
            data.append(record)
    return data

# 文件路径
file_path = 'mini1_196cm/20231028_015645_199.odom'

# 从文件中读取数据
odom_data = read_data_from_file(file_path)

# 计算平均DistancePerPulse
average_result = calculate_average_distance_per_pulse(odom_data)
print(f"Average Distance Per Pulse: {average_result}")
