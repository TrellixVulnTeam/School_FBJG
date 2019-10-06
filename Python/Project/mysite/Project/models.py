from django.db import models

class Alcohol(models.Model):
	name = models.CharField('Name', max_length=100, unique=True)
	company = models.ForeignKey('Company')
	description = models.TextField('Description', null=True, blank=True)
	kind = models.ForeignKey('Kind')
	cost = models.IntegerField('Price', null=True,)

	def __str__(self):
		return self.name

class Company(models.Model):
	name = models.CharField('Company name', max_length=50, unique=True)
	year = models.IntegerField('Year', null=True)

	def __str__(self):
		return self.name

class Kind(models.Model):
	name = models.CharField('Kind', max_length=50, unique=True)

	def __str__(self):
		return self.name
