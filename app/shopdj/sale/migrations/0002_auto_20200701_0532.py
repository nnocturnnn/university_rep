# Generated by Django 3.0.5 on 2020-07-01 05:32

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('sale', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='invoiceitem',
            name='product_name',
            field=models.CharField(default=None, max_length=50),
        ),
        migrations.AddField(
            model_name='invoiceitem',
            name='product_price',
            field=models.IntegerField(default=None),
        ),
    ]
