816
>>> '<spam>/<ham>/<eggs>'.find('ham')
8
>>> re.findall('<(.*?)>', '<spam>/<ham>/<eggs>')
['spam', 'ham', 'eggs']
>>> re.findall('<(.*)>', '<spam>/<ham>/<eggs>')
['spam>/<ham>/<eggs']
>>> re.findall('<(.*?)>', '<spam>...<ham>')
['spam', 'ham']
>>> re.findall('<(.*?)>', '<spam> / <ham><eggs>')
['spam', 'ham', 'eggs']
>>> re.findall('<(.*?)>/?<(.*?)>', '<spam>/<ham> ... <eggs><cheese>')
[('spam', 'ham'), ('eggs', 'cheese')]
>>> re.search('<(.*?)>/?<(.*?)>', 'todays menu: <spam>/<ham>...<eggs><s>').groups()
('spam', 'ham')
