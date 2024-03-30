FROM python:3.12

COPY requirements.txt .

RUN pip install --no-cache-dir -r requirements.txt

CMD ["tail", "-f", "/dev/null"]