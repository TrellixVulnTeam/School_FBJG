# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Alcohol',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('name', models.CharField(unique=True, max_length=100, verbose_name=b'Name')),
                ('description', models.TextField(null=True, verbose_name=b'Description', blank=True)),
                ('cost', models.IntegerField(null=True, verbose_name=b'Price')),
            ],
        ),
        migrations.CreateModel(
            name='Company',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('name', models.CharField(unique=True, max_length=50, verbose_name=b'Company name')),
                ('cost', models.IntegerField(null=True, verbose_name=b'Cost')),
            ],
        ),
        migrations.CreateModel(
            name='Kind',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('name', models.CharField(unique=True, max_length=50, verbose_name=b'Kind')),
            ],
        ),
        migrations.AddField(
            model_name='alcohol',
            name='company',
            field=models.ForeignKey(to='Project.Company'),
        ),
        migrations.AddField(
            model_name='alcohol',
            name='kind',
            field=models.ForeignKey(to='Project.Kind'),
        ),
    ]
