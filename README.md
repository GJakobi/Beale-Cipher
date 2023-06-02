# Beale-Cipher
Codifica e decodifica cifras de beale

## Ideação do projeto e mais informações sobre: 
https://wiki.inf.ufpr.br/maziero/doku.php?id=prog2:cifras_de_baele

## Entenda sobre as cifras:
https://pt.wikipedia.org/wiki/Cifras_de_Beale

# Uso
##### Codificar uma mensagem qualquer contida em um arquivo ASCII usando um livro cifra. ArquivoDeChaves é o caminho caso queira salvar o livro de chaves gerado
```./beale  -e  -b LivroCifra -m MensagemOriginal -o MensagemCodificada -c ArquivoDeChaves```

##### Decodificar uma mensagem, usando um arquivo de códigos 
```./beale  -d  -i MensagemCodificada  -c ArquivoDeChaves  -o MensagemDecodificada```

##### Decodificar uma mensagem usando o livro cifra
```./beale -d -i MensagemCodificada -b LivroCifra -o MensagemDecodificada ```

