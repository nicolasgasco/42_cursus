FROM python:3.12

COPY requirements.txt .
COPY ./data ./dslr/data
COPY ./app ./dslr/app

RUN pip install --no-cache-dir -r requirements.txt

CMD ["tail", "-f", "/dev/null"]