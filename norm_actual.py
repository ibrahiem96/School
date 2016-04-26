# encoding=utf-8
# norm.py

import requests


if __name__ == '__main__':

    r_handler = requests.get("http://files.vladstudio.com/joy/where_tahrs_live/wall/vladstudio_where_tahrs_live_2880x1800_signed.jpg")
    
    if r_handler.status_code == 200:

        print(r_handler.headers["Content-Length"])
        with open("test_normal.jpg", "wb") as file:
            file.write(r_handler.content)
