from django.contrib import admin
from .models import Alcohol, Company, Kind

# Register your models here.

admin.site.register(Alcohol)
admin.site.register(Company)
admin.site.register(Kind)
