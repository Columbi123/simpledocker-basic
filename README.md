# Docker + Nginx + FastCGI

Практический проект: C-приложение с FastCGI запускается в собственном Docker-образе с Nginx, а второй контейнер Nginx работает как reverse proxy.

## Состав

- `src/server/server.c` — простой FastCGI-сервер.
- `src/Dockerfile` — сборка контейнера с приложением, запуск непривилегированным пользователем и healthcheck.
- `src/nginx/nginx.conf` — внутренний Nginx (порт 81).
- `src/nginx_proxy/default.conf` — обратное проксирование (порт 8080).
- `src/docker-compose.yml` — два сервиса и изолированная bridge-сеть.
- `src/report.md` — отчёт с иллюстрациями работы стенда.

## Запуск

Требуется Docker Engine с поддержкой `docker compose`.

```bash
cd src
docker compose up --build -d
docker compose ps
curl -i http://localhost:8080/
curl -i http://localhost:8080/status
# после проверки:
docker compose down
```

Сервис доступен на `http://localhost:8080/`. Порт хоста можно изменить в `src/docker-compose.yml`.

> Проект выполнялся как учебный стенд. Контейнерную сборку следует дополнительно проверить на машине с Docker.
