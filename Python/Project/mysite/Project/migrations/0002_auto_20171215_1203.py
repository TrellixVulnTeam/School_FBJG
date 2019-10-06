# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('Project', '0001_initial'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='company',
            name='cost',
        ),
        migrations.AddField(
            model_name='company',
            name='year',
            field=models.IntegerField(null=True, verbose_name=b'Year'),
        ),
    ]
