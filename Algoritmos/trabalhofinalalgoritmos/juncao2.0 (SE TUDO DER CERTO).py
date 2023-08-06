

#iniciando listas,apenas alguns para deixar no catálogo inicial
lista_codigos=['1','2','3','4','5','6']#colocamos em str para nao bugar funcao de consulta
lista_nomes=["A bela e a Fera","Star Trek","Pinóquio","Os vingadores","Gente Grande","Interestelar"]
lista_tipos=[1,2,1,2,1,3]
lista_precos=[15.50,19.50,25.50,5.99,65.00,90.00]
lista_disponivel=[True,True,False,True,False,True]
lista_login=['bruninho157','pedroreidelas']
datas = ['25/07/2022','03/08/2022']
precototal=[25.50,65.00]

#----------------------------------------------------------------------------------------------------------------------------------------------------

def consultaindice(codigo_produto):#funcao para descobrir indice nas listas
    posicao=0
    codigo_produto=int(input("Digite o código do produto: "))
    while codigo_produto < 0:
        codigo_produto = int(input("Código negativo fera?Digite um positivo né: "))
    for c in range(len(lista_codigos)):
        for j in range(c):
            if str(codigo_produto) in (lista_codigos[c]):
                posicao = c
            
                break
            break
        if str(codigo_produto) not in lista_codigos:
            posicao = -1 #Para dizer se o produto esta cadastrado ou nao
        
    return posicao

#--------------------------------------------------------------------------------------------------------------------------------------------------

def atualizarProduto(codigo_produto):#funcao para atualizar produto
    codigo = consultaindice(codigo_produto)
    while codigo == -1:
        print("Produto não cadastrado,digite um código válido: ")
        codigo = consultaindice(codigo_produto)#puxa funcao para usar nesta funcao
        
    print("O que deseja atualizar?")
    print("Digite 1 para atualizar nome ")
    print("Digite 2 para atualizar o tipo ")
    print("Digite 3 para atualizar o preço ")
    print("Digite 4 para atualizar a disponibilidade ")
    x = int(input())
    while x > 4 or x <1:#checar
        x=int(input("Digite um código válido"))

    if x == 1:
        novonome=str(input("Digite o novo nome: "))
        lista_nomes[codigo] = novonome
    if x == 2:
        novotipo=int(input("Digite o novo tipo: "))
        if novotipo == 1:
            lista_tipos[codigo] = 1
        elif novotipo == 2:
            lista_tipos[codigo] = 2
        elif novotipo == 3:
            lista_tipos[codigo] = 3
    if x == 3:
        novopreco=float(input("Digite o novo preço: "))
        while novopreco <0:
            novopreco=float(input("Digite um valor válido para o preço: "))
        lista_precos[codigo] = novopreco
    if x == 4:
        novadisponibilidade = int(input("Digite a nova disponibilidade(1 para disponível e 2 para indisponível): "))
        while novadisponibilidade >2 or novadisponibilidade <1:
            novadisponibilidade = int(input("Digite um valor válido: "))
        if novadisponibilidade == 1:
            lista_disponivel[codigo] = True
        elif novadisponibilidade == 2:
            lista_disponivel[codigo] = False
    print("Produto atualizado com sucesso! ")

#---------------------------------------------------------------------------------------------------------------------------------------------

def relatorioProdutos(lista_nomes):#funcao para relatorio
    indices = list(range(len(lista_nomes)))#novas listas a partir de uma lista de indices
    indices.sort(key=lambda i: lista_nomes[i])
    novalista_nome=[lista_nomes[i] for i in indices ]
    novalista_codigo=[lista_codigos[i]for i in indices]
    novalista_tipo = [lista_tipos[i]for i in indices]
    novalista_preco = [lista_precos[i]for i in indices]
    
    f = int(input("O que você deseja visualizar?(0 para todos,1 para filmes,2 para series,\n3 para documentarios,4 para produtos disponiveis para venda,\nou 5 para produtos indisponíveis): "))
    while f <0 or f >5:
        f = int(input("Digite um valor válido: "))

    if f == 0:
        
        print("{:<8} {:<25} {:<18} {:<12}".format('Código',"Nome","Tipo","Preço"))#{:8} é a distancia,para fazer tabela
        for u in range(len(lista_nomes)):
            chamartipo = transformarTipo(novalista_tipo)
            posicao3 = u
            print("{:<8} {:<25} {:<18} {:<12.2f}".format(novalista_codigo[posicao3],novalista_nome[posicao3],chamartipo[posicao3],novalista_preco[posicao3]))
            
    if f ==1:
        print("{:<8} {:<25} {:<18} {:<12}".format('Código',"Nome","Tipo","Preço"))
        for u in range(len(novalista_tipo)):
            posicao3=-1
            if novalista_tipo[u] == 2:
                posicao3 = u
            else:
                continue
            if posicao3 != -1:
                chamartipo = transformarTipo(novalista_tipo)

                print("{:<8} {:<25} {:<18} {:<12.2f}".format(novalista_codigo[posicao3],novalista_nome[posicao3],chamartipo[posicao3],novalista_preco[posicao3]))
            posicao3 = -1
    if f ==2:
        print("{:<8} {:<25} {:<18} {:<12}".format('Código',"Nome","Tipo","Preço"))
        for u in range(len(novalista_tipo)):
            posicao3=-1
            if novalista_tipo[u]== 1:
                posicao3 = u
            else:
                continue
            
            if posicao3 != -1:
                chamartipo = transformarTipo(novalista_tipo)
                print("{:<8} {:<25} {:<18} {:<12.2f}".format(novalista_codigo[posicao3],novalista_nome[posicao3],chamartipo[posicao3],novalista_preco[posicao3]))
            posicao3 = -1

    if f ==3:
        print("{:<8} {:<25} {:<18} {:<12}".format('Código',"Nome","Tipo","Preço"))
        for u in range(len(novalista_tipo)):
            posicao3=-1
            if novalista_tipo[u]==3:
                posicao3 = u
            else:
                continue
            if posicao3 != -1:    
                chamartipo = transformarTipo(novalista_tipo) 
                print("{:<8} {:<25} {:<18} {:<12.2f}".format(novalista_codigo[posicao3],novalista_nome[posicao3],chamartipo[posicao3],novalista_preco[posicao3]))
            posicao3 = -1       
    if f ==4:
        print("{:<8} {:<25} {:<18} {:<12}".format('Código',"Nome","Tipo","Preço"))
        for u in range(len(lista_disponivel)):
            posicao3 = -1
            if lista_disponivel[u] ==True:
                posicao3 = u
            else:
                continue
            if posicao3 != -1:
                chamartipo = transformarTipo(novalista_tipo)
                print("{:<8} {:<25} {:<18} {:<12.2f}".format(novalista_codigo[posicao3],novalista_nome[posicao3],chamartipo[posicao3],novalista_preco[posicao3]))
            posicao3 = -1
    if f ==5:
        print("{:<8} {:<25} {:<18} {:<12}".format('Código',"Nome","Tipo","Preço"))
        for u in range(len(lista_disponivel)):
            posicao3 = -1
            if lista_disponivel[u] ==False:
                posicao3 = u
            else:
                continue    
            if posicao3 != -1:
                chamartipo = transformarTipo(novalista_tipo)
                print("{:<8} {:<25} {:<18} {:<12.2f}".format(novalista_codigo[posicao3],novalista_nome[posicao3],chamartipo[posicao3],novalista_preco[posicao3]))
            posicao3 = -1

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

def cadastroDeProduto(codigo_produto,nome_produto,tipo_produto,preco_produto,disponivel):#funcao para cadastro produto
    condicao = 0
    while condicao ==0:
        codigo_produto=int(input("Digite o código do produto: "))
        if str(codigo_produto) in lista_codigos:#enquanto o codigo ja estiver na lista,pedir para digitar um valor válido
            print("O código já existe,digite outro valor")
        elif codigo_produto <0:
            print("Digite um código maior que 0")
        else:
            condicao = 1#se tudo estiver certo,continue
    if condicao ==1:
        lista_codigos.append(str(codigo_produto))
        nome_produto=str(input("Digite o nome do produto: "))
        lista_nomes.append(nome_produto)
        tipo_produto=int(input("Digite o tipo (1 para série,2 para filme e 3 para documentário): "))
        while tipo_produto <1 or tipo_produto >3:
            tipo_produto = int(input("Digite um valor válido"))#checar valor
        if tipo_produto==1:
            lista_tipos.append(1)
        elif tipo_produto==2:
            lista_tipos.append(2)
        elif tipo_produto==3:
            lista_tipos.append(3)
        preco_produto=float(input("Digite o preço do produto: "))
        while preco_produto <0:
            preco_produto = float(input("Digite um valor válido para o preço: "))
        lista_precos.append(preco_produto)
        disponivel=int(input("O produto pode ser vendido?(Digite 1 para sim e 2 para não): "))
        while disponivel <1 or disponivel >2:
            disponivel=int(input("Digite um valor válido: "))#checar
        if disponivel==1:
            lista_disponivel.append(True)
        elif disponivel==2:
            lista_disponivel.append(False)
        print("Cadastro realizado com sucesso!")

#------------------------------------------------------------------------------------------------------------------------------------------

def transformarTipo(lista_tipos):#transforma o tipo de numeros para string
    nova_lista_tipos=[]
    for c in range(len(lista_tipos)):
        if lista_tipos[c] == 1:
            nova_lista_tipos.append("Série")
        elif lista_tipos[c] == 2:
            nova_lista_tipos.append("Filme")
        elif lista_tipos[c] == 3:
            nova_lista_tipos.append("Documentário")
    return nova_lista_tipos

#------------------------------------------------------------------------------------------------------------------------------------------

def registrarCompra(lista_tipos):#funcao para registrar compra
    login = str(input("Digite o login do cliente: "))
    if login not in lista_login:
        lista_login.append(login)#se login n estiver cadastrado,cadastra automaticamente
    soma=0
    carrinho_preco=[]
    carrinho_codigo=[]
    carrinho_tipo=[]
    carrinho_nome=[]
    condicao=1
    while True :
        while condicao ==1:#valor para verificar 
            indice = consultaindice(codigo_produto)
            if lista_disponivel[indice] == False:
                print("O produto não está disponível para venda,por favor digite outro código!")
            elif indice == -1:
                print("Código não cadastrado,digite outro código!")
            else:
                condicao=0  #se tudo estiver certo,variavel recebe 0 e segue o baile
        
        if condicao == 0:
            print("Este é seu produto:" , lista_nomes[indice])
            confirmacao = int(input("Deseja adicionar este produto ao carrinho?(1 para sim e 2 para não): "))
            while confirmacao > 2 or confirmacao <1:
                confirmacao = int(input("Digite um valor válido: "))
            if confirmacao == 1:
                carrinho_codigo.append(lista_codigos[indice])
                carrinho_nome.append(lista_nomes[indice])
                carrinho_preco.append(lista_precos[indice])
                

                if lista_tipos[indice] == 1:#transforma tipo de numero para string
                    carrinho_tipo.append("Série")
                if lista_tipos[indice] == 2:
                    carrinho_tipo.append("Filme")
                if lista_tipos[indice] == 3:
                    carrinho_tipo.append("Documentário")
                
                soma += lista_precos[indice]#soma os valores dos produtos para printar depois
                
                condicao = 1 #variavel volta a receber 1 para verificar novamente
            else:
                condicao = 1
                
        continuar = int(input("Deseja continuar a adicionar itens?(1 para sim e 2 para não)"))
        while continuar > 2 or continuar < 1:
            continuar = int(input("Digite um valor válido: "))
        if continuar == 2:
            precototal.append(soma)
            precototal.append(lista_precos[indice])#adicionando a compra nas listas de compras
            datas.append("08/08/2022")
            lista_login.append(login)
            print("Compra realizada com sucesso,seu cupom abaixo:")
            print("{:<8} {:<25} {:<18} {:<12}".format('Código','Nome','Tipo','Preço'))
            for c in range(len(carrinho_codigo)):
                indice = c
                print("{:<8} {:<25} {:<18} {:<12.2f}".format(carrinho_codigo[indice],carrinho_nome[indice],carrinho_tipo[indice],carrinho_preco[indice]))
                    
            
            print("{:<8} {:<25} {:<18} {:<12.2f}".format("","","TOTAL",soma))#so pra printar o total
                
            break

#-------------------------------------------------------------------------------------------------------------------------------------------

def relatorioCompras(lista_login,datas,precototal):
    print("{:<10} {:<25} {:<12}".format("Data","Login","Preço Total"))#só printa
    for c in range(len(datas)):
        indice = c
        print("{:<10} {:<25} {:<12.2f}".format(datas[indice],lista_login[indice],precototal[indice]))



#--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#A PARTIR DAQUI PROGRAMA PRINCIPAL
print("-------------------------------------------------------------------------------------------------")
print("Bem vindo ao NerdFlix escravo de seu proletariado,o site de streaming mais atualizado do planeta!")
print()
print("Digite a função de deseja utilizar: ")#boas vindas
print("Para cadastrar um produto,digite 'cadastrar' ou 1")
print("Para consultar um produto do catálogo,digite 'consultar' ou 2")
print("Para atualizar um produto do catálogo,digite 'atualizar' ou 3")
print("Para acessar o relatório,digite 'relatorio' ou 4")
print("Para registrar uma compra,digite 'registrar' ou 5")
print("Para ver as compras anteriores,digite 'compras' ou 6")
print("Para encerrar o programa,digite 'sair' ou 0")
print("---------------------------------------------------------------------")

while True:
    acao=str(input())
    codigo_produto=0#Iniciando variaveis
    nome_produto=0
    tipo_produto=0
    preco_produto=0
    disponivel=0
    while acao != '1' and acao != '2' and acao != '3' and acao !='4' and acao != '5' and acao != '6' and acao !='0' and acao !='consultar' and acao != 'cadastrar' and acao !='atualizar' and acao !='relatorio' and acao !='compras' and acao!= 'registrar' and acao!='sair':
        acao = str(input("Valor incorreto,por favor digite um valor válido: "))
    if acao == "cadastrar" or acao =="1":
        print("-----------------------------------------")
        print("********** CADASTRO DE PRODUTO **********")
        print("-----------------------------------------")
        chamadocadastro=cadastroDeProduto(codigo_produto,nome_produto,tipo_produto,preco_produto,disponivel)#Chamando funcao
    if acao == "2" or acao == "consultar":
        print("---------------------------------------")
        print("********** CONSULTAR PRODUTO **********")
        print('---------------------------------------')
        chamadoconsulta = consultaindice(codigo_produto)
        if chamadoconsulta == -1:#na funcao do indice,-1 significa que nao está presente na lista
            print("Produto não cadastrado!") 
        else:
            print("Este é seu produto: ")
            print("Nome: ",lista_nomes[chamadoconsulta])
            print("Tipo: ",lista_tipos[chamadoconsulta])
            print(f"Preço = {lista_precos[chamadoconsulta]:.2f}")
            print("Disponibilidade: ",lista_disponivel[chamadoconsulta])
    if acao == "3" or acao =="atualizar":
        print("---------------------------------------")
        print("********** ATUALIZAR PRODUTO **********")
        print("---------------------------------------")
        chamadoatualizacao = atualizarProduto(codigo_produto)
    if acao == "4" or acao =="relatorio":
        print("-------------------------------------------")
        print("********** RELATÓRIO DE PRODUTOS **********")
        print("-------------------------------------------")
        chamadorelatorio = relatorioProdutos(lista_nomes)
    if acao == "5" or acao == "registrar":
        print("--------------------------------------")
        print("********** REGISTRAR COMPRA **********")
        print("--------------------------------------")
        chamadacompra = registrarCompra(lista_tipos)
    if acao == "6" or acao == "compras":
        print("------------------------------------------")
        print("********** RELATÓRIO DE COMPRAS **********")
        print("------------------------------------------")
        chamarcompras = relatorioCompras(lista_login,datas,precototal)
    if acao == "0" or acao == "sair":
        print("-----------------------------------------")
        print("********** ENCERRANDO PROGRAMA **********")
        print("-----------------------------------------")
        break
    
    print("---------------------------------------------------------------------")
    print("Para cadastrar um produto,digite 'cadastrar' ou 1")
    print("Para consultar um produto do catálogo,digite 'consultar' ou 2")
    print("Para atualizar um produto do catálogo,digite 'atualizar' ou 3")
    print("Para acessar o relatório,digite 'relatorio' ou 4")
    print("Para registrar uma compra,digite 'registrar' ou 5")
    print("Para ver as compras anteriores,digite 'compras' ou 6")
    print("Para encerrar o programa,digite 'sair' ou 0")
    print("---------------------------------------------------------------------")
        
    

    
