from django.shortcuts import render, render_to_response, get_object_or_404
from django.http import HttpResponse
from django.template import loader, RequestContext
from Project.forms import AlcoholForm, CompanyForm, KindForm
from django.template.context_processors import csrf


from .models import Alcohol, Company, Kind
from django import forms

def index(request):
    return render_to_response('Project/index.html')

def alcohol(request, alcohol_id):
	alcohol = get_object_or_404(Alcohol, pk=alcohol_id)
	return render(request, 'Project/alcohol.html', {'alcohol' : alcohol })

def company(request, company_id):
	company = get_object_or_404(Company, pk=company_id)
	alcohols = Alcohol.objects.all().filter(company_id = company_id)
	return render(request, 'Project/company.html', {'company' : company, 'alcohols' : alcohols })

def alcohols(request):
	alcohols = Alcohol.objects.all().order_by('name')
	context = {'alcohols' : alcohols }
	return render(request, 'Project/alcohols.html', context)

def companys(request):
	companys = Company.objects.all().order_by('name')
	context = {'companys' : companys }
	return render(request, 'Project/companys.html', context)

def polls(request):
    return HttpResponse("Hello, world. You're at the polls index.")

###########################################################################

def search(request, first_letter = None):
    searched_alcohol = request.GET.get('alcohol_input')
    searched_company = request.GET.get('company_input')

    if first_letter is not None:
        alcohols = Alcohol.objects.all().filter(name__istartswith = first_letter)
    elif searched_alcohol is not None:
        alcohols = Alcohol.objects.all().filter(name__icontains = searched_alcohol)
    elif searched_company is not None:
        alcohols = Alcohol.objects.all().filter(company__name__icontains = searched_company)
    else:
        alcohols = None
    
    alphabet = [chr(c) for c in range(ord('A'), ord('Z') + 1)] 
    
    context = {
    	'searched_company': searched_company, 
    	'searched_alcohol': searched_alcohol, 
    	'first_letter': first_letter, 
    	'alcohols': alcohols, 
    	'alphabet': alphabet
    }
    return render(request, 'Project/search.html', context)

#########################################################################

def alcoholform(request):
    success = False
    if request.method == 'POST':
        form = AlcoholForm(request.POST, request.FILES)
        if form.is_valid():
            form.save()
            success = True
            return render(request, 'Project/alcohol_form.html', {'form' : form, 'success' : success})
    else:
        form = AlcoholForm()
    return render(request, 'Project/alcohol_form.html', {'form' : form, 'success' : success})

def companyform(request):
    success = False
    if request.method == 'POST':
        form = CompanyForm(request.POST, request.FILES)
        if form.is_valid():
            form.save()
            success = True
            return render(request, 'Project/company_form.html', {'form' : form,'success' : success})
    else:
        form = CompanyForm()
    return render(request, 'Project/company_form.html', {'form' : form, 'success' : success})

def kindform(request):
    success = False
    if request.method == 'POST':
        form = KindForm(request.POST, request.FILES)
        if form.is_valid():
            form.save()
            success = True
            return render(request, 'Project/kind_form.html', {'form' : form, 'success' : success})
    else:
        form = KindForm()
    return render(request, 'Project/kind_form.html', {'form' : form, 'success' : success})


