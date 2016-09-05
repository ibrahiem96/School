# encoding=utf-8
# norm.py

# Importing requests the module here
# that we pip installed earlier
import requests

# Equivalent to a main function
# in C, Java or Go
if __name__ == '__main__':

    # Making a HTTP GET request
    resp = requests.get("http://files.vladstudio.com/joy/where_tahrs_live/wall/vladstudio_where_tahrs_live_2880x1800_signed.jpg")

    # Checking the response to see if everything is OK,
    # this is what the 200 code signifies
    if resp.status_code == 200:

        # We can access the headers of a Response
        # object as well. In this case
        # we just print out the
        # Content-Length to
        # see how big the
        # response was
        print(resp.headers["Content-Length"])

        # We use a context manager here, by using
        # the `with` statement. We use it
        # to open a file called, and
        # write bytes to it, 'wb'.
        with open("test_normal.jpg", "wb") as f:

            # We write out the binary contents
            # of the response to the file.
            f.write(resp.content)
