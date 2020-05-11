#extract tables from wikipedia
from pandas.io.html import read_html
page = 'https://www.ft.com/content/691390ca-53d9-11ea-90ad-25e377c0ee1f?fbclid=IwAR3TfgUYCgwsZLN-ad-GnFN7lUcUEurB86SHRHVJewO6ZkL3XrwMGjxzJm4'

wikitables = read_html(page,  attrs={"class":"o-table o-table--row-stripes o-table--compact o-table--responsive-overflow o-table--sortable"})

print ("Extracted {num} wikitables".format(num=len(wikitables)))
