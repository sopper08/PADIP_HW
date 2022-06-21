import cv2 as cv
import numpy as np
import sys
from pathlib import Path

def main():
    if len(sys.argv) != 2:
        print("Usage: python3 long_long_image.py <image_folder>")
        return
    
    image_folder = Path(sys.argv[1])
    if not image_folder.exists():
        print("Image folder does not exist")
        return

    images = []
    image_path_list = [image_path for image_path in image_folder.iterdir() if image_path.is_file()]
    image_path_list = sorted(image_path_list)

    for image_path in image_path_list:
        image = cv.imread(str(image_path))
        if image is None:
            print("Failed to read image: " + str(image_path))
            continue
        images.append(image)

    if len(images) == 0:
        print("No images found")
        return
    
    # long_long_image = images[0]
    max_height = max([image.shape[0] for image in images])
    images = [cv.resize(image, (0, 0), fx=max_height/image.shape[0], fy=max_height/image.shape[0]) for image in images]
    images = np.concatenate(images, axis=1)
    # for i in range(1, len(images)):
        # long_long_image = np.concatenate((long_long_image, images[i]), axis=1)

    cv.imshow("Results", images)
    cv.waitKey(0)
    cv.destroyAllWindows()

    images_path = image_folder / "long_long_image.jpg"
    cv.imwrite(str(images_path), images)

if __name__ == '__main__':
    main()