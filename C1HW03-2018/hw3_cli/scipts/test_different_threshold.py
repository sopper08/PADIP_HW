import sys
import os

def main():
    filename = sys.argv[1]
    filter_size = int(sys.argv[2])
    sigma = float(sys.argv[3])
    lower_threshold = int(sys.argv[4])
    upper_threshold = int(sys.argv[5])
    for threshold in range(lower_threshold, upper_threshold + 1, 400):
        command = f"./hw3_cli {filename} {filter_size:02} {sigma:1.1f} {threshold:04d}"
        os.system(command)

if __name__ == '__main__':
    main()