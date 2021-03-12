from flask import Flask, render_template
from flask_wtf import FlaskForm
from wtforms import FloatField, SelectField, SubmitField
from wtforms.validators import DataRequired
import csv

app = Flask(__name__)
app.config['SECRET_KEY'] = '7zSogujyV0)V@KTE<!_imSi-l-t%%-4I' 

class ConversionForm(FlaskForm): # это класс для генерации форм с валютами
    first_val = FloatField(
        'Enter the value',
        validators=[DataRequired()]
    )
    first_unit = SelectField(
        choices=[
            ('EUR', 'EUR'),
            ('UAN', 'UAN'),
            ('USD', 'USD')
        ]
    )
    second_unit = SelectField(
        choices=[
            ('EUR', 'EUR'),
            ('UAN', 'UAN'),
            ('USD', 'USD')
        ]
    )
    submit = SubmitField('Convert')


@app.route('/', methods=['GET', 'POST']) # это значит что мы проверяем путь http://127.0.0.1:5000 по пути /
def index():
    form = ConversionForm() 
    result = None
    if form.validate_on_submit():
        first_val = form.first_val.data # это мы берем данные с ячейки с текстом
        first_unit = form.first_unit.data # первая валюта 
        second_unit = form.second_unit.data # вторая
        with open('data.csv', newline='') as csvfile: # открываем файл с валютами и парсим его
            spamreader = csv.reader(csvfile, delimiter=',')
            for row in spamreader:
                if row[0] == first_unit: # с 43-48 сами вычисление 
                    if row[1] == second_unit:
                        result = first_val / float(row[2])
                if row[1] == first_unit:
                    if row[0] == second_unit:
                        result = first_val * float(row[2])
    return render_template('index.html', form=form, result=result) #возвращаем html и вставляем данные которые вышли


if __name__ == '__main__':
    app.run(debug=True)

