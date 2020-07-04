import win32gui
import win32con

handle = win32gui.FindWindow(None, r'qBittorrent v4.2.5')

win32gui.PostMessage(handle,win32con.WM_CLOSE,0,0)