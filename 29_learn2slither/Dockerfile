FROM python:3.13

COPY requirements.txt .
COPY ./board ./learn2slither/board

RUN pip install --no-cache-dir -r requirements.txt

CMD ["tail", "-f", "/dev/null"]