from django.conf.urls import include, url
from django.contrib import admin
from Project import views

import Project.views

urlpatterns = [

    url(r'^admin/', include(admin.site.urls)),

    url(r'^$', Project.views.index, name='index'),
    url(r'^companys/', Project.views.companys, name='companys'),
###################################################################################
    url(r'^search/$', views.search, name = 'search'),
    url(r'^search/([a-zA-Z])/$', views.search, name = 'search_value'),
###################################################################################
    url(r'^alcohols/', Project.views.alcohols, name='alcohols'),
    url(r'^alcohol/(?P<alcohol_id>[0-9]+)/', Project.views.alcohol, name='alcohol'),
    url(r'^company/(?P<company_id>[0-9]+)/', Project.views.company, name='company'),

###################################################################################
    url(r'^alcohol_form/$', views.alcoholform, name = 'alcoholform'),
    url(r'^company_form/$', views.companyform, name = 'companyform'),
    url(r'^kind_form/$', views.kindform, name = 'kindform'),
###################################################################################
    url(r'^polls/', Project.views.polls, name='polls'),
]
