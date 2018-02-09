# The Build
FROM python:3.6

# Force the binary layer of the stdout and stderr streams (which is available as their buffer attribute) to be unbuffered.
# The text I/O layer will still be line-buffered if writing to the console, or block-buffered if redirected to a non-interactive file.
ENV PYTHONUNBUFFERED 1

RUN mkdir /app

WORKDIR /app

COPY requirements.txt /app/

RUN pip install -r requirements.txt
