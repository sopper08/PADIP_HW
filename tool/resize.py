import sys
import cv2 as cv


def main():
    if len(sys.argv) != 3:
        print("Usage: resize.py <filename> <ratio>")
        sys.exit(1)
    filename = sys.argv[1]
    mat = cv.imread(filename, cv.IMREAD_UNCHANGED)
    ratio = float(sys.argv[2])
    mat = cv.resize(mat, (0, 0), fx=ratio, fy=ratio)
    cv.imwrite(filename[:-4] + sys.argv[2] + ".jpg", mat)

if __name__ == "__main__":
    main()