# encoding=utf-8
# para_async.py

import asyncio
import itertools

import aiohttp


async def get_image(url, parts):
    async def get_while_active(u, i, start, end):
        #print(i, start, end)
        async with aiohttp.get(u, headers={"Range": "bytes={}-{}".format(start, end - 1 if end else "")}) as _resp:
            return i, await _resp.read()

    async with aiohttp.head(url) as resp:
        size = int(resp.headers["Content-Length"])

    ranges = list(range(0, size, size // parts))

    res, _ = await asyncio.wait([get_while_active(url, i, start, end) for i, (start, end) in
         enumerate(itertools.zip_longest(ranges, ranges[1:], fillvalue=""))])

    sorted_result = sorted(task.result() for task in res)
    return b"".join(data for _, data in sorted_result)


if __name__ == '__main__':
    image = "http://files.vladstudio.com/joy/where_tahrs_live/wall/vladstudio_where_tahrs_live_2880x1800_signed.jpg"
    loop = asyncio.get_event_loop()
    handler = loop.run_until_complete(get_image(image, 16))

    with open("test_para_async.jpeg", "wb") as fi:
        print(len(handler))
        fi.write(handler)
