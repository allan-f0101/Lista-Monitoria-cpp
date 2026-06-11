print('Bem, amigos da rede! Sistema de Estatísticas VAR Edition no ar. Aguardando comandos...')
dados = {}

def chaveordenacao(item):
    jogador = item[0]
    selecao, gols, assistencias, passes, amarelos, vermelhos = item[1]
    return (-gols, -assistencias, vermelhos, amarelos, -passes, selecao, jogador)

fim = False
while fim ==False:
    entrada=input().split()
    comando = entrada[0]
    if comando=='*ADD':
        jogador =entrada[1]
        selecao =entrada[2]
        gols =int(entrada[3])
        assistencias=int(entrada[4])
        passes =int(entrada[5])
        amarelos= int(entrada[6])
        vermelhos = int(entrada[7])
        if jogador in dados and dados[jogador][0] == selecao:
            tselecao, tgols, tassistencias, tpasses, tamarelos, tvermelhos = dados[jogador]
            dados[jogador] = (
                tselecao,
                tgols + gols,
                tassistencias + assistencias,
                tpasses + passes,
                tamarelos + amarelos,
                tvermelhos + vermelhos
            )
        else:
            dados[jogador] = (selecao, gols, assistencias, passes, amarelos, vermelhos)
    elif comando == '*DEL':
        jogador =entrada[1]
        selecao= entrada[2]
        apagou=False
        while apagou == False:
            if jogador in dados and dados[jogador][0]== selecao:
                del dados[jogador]
                print(f'O jogador: {jogador} da seleção: {selecao} foi retirado do sistema')
                apagou =True
            else:
                print(f'O jogador: {jogador} da seleção: {selecao} não foi encontrado insira uma outra combinação de jogador e seleção:')
                nova = input().split()
                jogador = nova[0]
                selecao = nova[1]
    elif comando =='*BUSCAR':
        jogador=entrada[1]
        selecao=entrada[2]
        if jogador in dados and dados[jogador][0] == selecao:
            tselecao, gols, assistencias, passes, amarelos, vermelhos = dados[jogador]
            print(f'{jogador} ({selecao}): {gols}G, {assistencias}A, {passes}P, {amarelos}CA, {vermelhos}CV')
        else:
            if jogador == 'Neymar':
                print("E o pessoal tá lá: 'será que Carlo Ancelotti vai convocar o Neymar?'")
            else:
                print(f'Jogador não encontrado na seleção {selecao}')
    elif comando == '*DESTAQUE_SELECAO':
        selecao = entrada[1]
        lista=[]
        for jogador in dados:
            if dados[jogador][0] == selecao:
                lista.append((jogador, dados[jogador]))
        if len(lista) == 0:
            print(f'Nenhum dado encontrado para a seleção {selecao}')
        else:
            lista = sorted(lista, key = chaveordenacao)
            melhor = lista[0]
            jogador = melhor[0]
            tselecao, gols, assistencias, passes, amarelos, vermelhos = melhor[1]
            print(f'Destaque da {selecao}: {jogador} {gols} gols, {assistencias} assistências')
    elif comando == '*BOLA_DE_OURO':
        if len(dados) == 0:
            print('Nenhum jogador registrado no torneio')
        else:
            lista =list(dados.items())
            lista =sorted(lista, key = chaveordenacao)
            melhor= lista[0]
            jogador= melhor[0]
            selecao, gols, assistencias, passes, amarelos, vermelhos = melhor[1]
            print(f'Bola de Ouro atual: {jogador} {selecao} com {gols} gols')
    elif comando== '*FIM':
        if len(dados) == 0:
            print('Nenhum jogador registrado para o ranking final.')
        else:
            lista = list(dados.items())
            lista = sorted(lista, key = chaveordenacao)
            print('Ranking Final:')
            posicao = 1
            for item in lista:
                jogador = item[0]
                selecao, gols, assistencias, passes, amarelos, vermelhos = item[1]
                print(f'{posicao}. {jogador} ({selecao}) - G: {gols}, A: {assistencias}, P: {passes}, CA: {amarelos}, CV: {vermelhos}')
                posicao = posicao + 1
        fim = True
