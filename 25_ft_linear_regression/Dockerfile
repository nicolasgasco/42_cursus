FROM python:3.12

COPY requirements.txt .
COPY ./data ./ft_linear_regression/data
COPY ./app ./ft_linear_regression/app

RUN pip install --no-cache-dir -r requirements.txt

CMD ["tail", "-f", "/dev/null"]