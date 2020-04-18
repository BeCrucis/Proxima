






with open('adyacency_edwardpara_l6.txt', 'r', encoding='utf-8') as f:

    data = f.read().splitlines()

linea = data[0]

facebook_id = linea.split(']')[0]
facebook_id = facebook_id.replace('[', '')

facebook_name = linea.split(']')[1]
facebook_name = facebook_name.replace('[', '')

facebook_connections = linea.split(']')[2]
facebook_connections = facebook_connections.split('{')[1]
facebook_connections = facebook_connections.replace('}', '')

# print(facebook_id)
# print(facebook_name)
# print(facebook_connections)


diccionario = { 'yuri' : ['edward', 'silva','jhansito','daniel'], 
'edward' : ['chucho', 'edward', 'jhansito'], 
'jose' : ['joj']
}

lista = []

for key in diccionario:

    lista_interna = diccionario[key]
    lista.append(key)
    
    for elemento in lista_interna:
        lista.append(elemento)

print(lista)

lista = list(set(lista))
print(lista)