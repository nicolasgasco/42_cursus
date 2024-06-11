FROM python:3.12

COPY requirements.txt .
COPY ./data ./multilayer_perceptron/data
COPY ./app ./multilayer_perceptron/app

RUN pip install --no-cache-dir -r requirements.txt

CMD ["tail", "-f", "/dev/null"]