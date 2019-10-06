
from django import forms
from .models import Alcohol, Company, Kind


class AlcoholForm(forms.ModelForm):
    class Meta:
        model = Alcohol
        fields = "__all__"

class CompanyForm(forms.ModelForm):
    class Meta:
        model = Company
        fields = "__all__"
        
class KindForm(forms.ModelForm):
    class Meta:
        model = Kind
        fields = "__all__"
