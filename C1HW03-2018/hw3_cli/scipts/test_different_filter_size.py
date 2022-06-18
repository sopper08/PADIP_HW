import sys
import os

def main():
    filename = sys.argv[1]
    lower_size = int(sys.argv[2])
    upper_size = int(sys.argv[3])
    sigma = float(sys.argv[4])
    threshold = int(sys.argv[5])
    for size in range(lower_size, upper_size + 1, 2):
        command = f"./hw3_cli {filename} {size:02} {sigma:1.1f} {threshold:04d}"
        os.system(command)

if __name__ == '__main__':
    main()