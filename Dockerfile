FROM tiangolo/uwsgi-nginx-flask:python3.7
RUN /usr/local/bin/python -m pip install --upgrade pip
COPY requirements.txt requirements.txt
RUN pip install -r requirements.txt

COPY ./backend /app