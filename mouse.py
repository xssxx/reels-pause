import pyautogui
import time
from PIL import ImageGrab

def get_mouse_color():
    x, y = pyautogui.position()
    screenshot = ImageGrab.grab()
    color = screenshot.getpixel((x, y))

    return color


if __name__ == "__main__":
    time.sleep(1.5)
    pyautogui.click()
    current = get_mouse_color()
    
    while True:
        pixel_color = get_mouse_color()
        print(pixel_color[0])
        # if pixel color change > 4, then click
        if abs(pixel_color[0] - current[0]) > 4:
            pyautogui.click()
            break