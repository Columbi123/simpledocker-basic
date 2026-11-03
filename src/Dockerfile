FROM debian:bookworm-slim

COPY server/server.c /tmp/server.c

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        nginx \
        gcc \
        libc6-dev \
        libfcgi-dev \
        libfcgi0ldbl \
        spawn-fcgi \
        curl && \
    gcc /tmp/server.c -o /usr/local/bin/mini_server -lfcgi && \
    apt-get purge -y gcc libc6-dev libfcgi-dev && \
    apt-get autoremove -y && \
    rm -rf /var/lib/apt/lists/* /tmp/server.c && \
    useradd --system --no-create-home --shell /usr/sbin/nologin appuser

COPY nginx/nginx.conf /etc/nginx/nginx.conf

USER appuser

HEALTHCHECK --interval=30s --timeout=3s \
    CMD curl -fsS http://127.0.0.1:81/status || exit 1

CMD ["sh", "-c", "spawn-fcgi -p 8080 /usr/local/bin/mini_server && nginx -g 'daemon off;'"]
