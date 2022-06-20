import sys
import cv2 as cv


def main():
    if len(sys.argv) != 2:
        print("Usage: to_jpg.py <filename>")
        sys.exit(1)
    filename = sys.argv[1]
    cv.imwrite(filename[:-4] + ".jpg", cv.imread(filename, cv.IMREAD_UNCHANGED))

    

if __name__ == "__main__":
    main()