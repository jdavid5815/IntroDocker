# The Build
FROM alpine:3.7 as builder

RUN mkdir /build

WORKDIR /build

RUN apk update && apk add build-base gcc abuild binutils binutils-doc gcc-doc

ADD . /build

ENV EXTRA_FLAGS="-O3 -std=c99"

RUN make && make strip


# The Server
FROM alpine:3.7 as server

LABEL maintainer="jan.david@evolane.be"

RUN mkdir /app

WORKDIR /app

COPY --from=builder /build/dtime /app/

EXPOSE 13

STOPSIGNAL SIGINT

CMD ["/app/dtime"]
