import serial
import pyautogui

Arduino_Serial = serial.Serial('/dev/ttyACM1',9600)
X='a'

while 1:

	incoming_data = str(Arduino_Serial.readline())
	print(incoming_data)
	if 'next2' in incoming_data :
		pyautogui.hotkey('ctrl', 'pgdn')
	if 'next1' in incoming_data :
		pyautogui.hotkey('ctrl', 'pgup')
	if 'up2' in incoming_data:
		pyautogui.press('space')
	if 'down1' in incoming_data:
		pyautogui.scroll(-100)
	if 'up1' in incoming_data:
		pyautogui.scroll(100)
	if 'down2' in incoming_data :
		pyautogui.press('space')
	if ('next2' in incoming_data) & ('next1' in X):
		pyautogui.keyDown('alt')
		pyautogui.press('tab')
		pyautogui.keyUp('alt')
	if ('next1' in incoming_data) & ('next2' in X):
		pyautogui.keyDown('win')
		pyautogui.press('prtsc')
		pyautogui.keyUp('win')
	X=incoming_data
	incoming_data = "";