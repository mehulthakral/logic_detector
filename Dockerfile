FROM tiangolo/uwsgi-nginx-flask:python3.7

COPY ./backend /app

COPY requirements.txt requirements.txt
RUN pip install -r requirements.txt