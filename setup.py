'''
Created on March 7, 2017
Copyright (c) 2017
Harvard FAS Research Computing
All rights reserved.

@author: Aaron Kitzmiller
'''

import os
from setuptools import setup, find_packages

setup(
    name = "lookkool",
    version = "0.2.0",
    author='Aaron Kitzmiller <aaron_kitzmiller@harvard.edu>',
    author_email='aaron_kitzmiller@harvard.edu',
    description='Palindrome detector',
    license='LICENSE.txt',
    url='http://pypi.python.org/pypi/ha/',
    packages = ['lookkool'],
    long_description='Palindrom detector',
    classifiers=[
        "Development Status :: 3 - Alpha",
        "Topic :: Utilities",
    ],
)
