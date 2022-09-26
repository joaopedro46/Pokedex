//Struct para armazenar dados dos pokemons
typedef struct
{
    int id;
    char nome[100];
    char tipo[100];
    float altura;
    float peso;
    int attack;
    int SP_attack;
    int defense;
    int SP_defense;
    int velocidade;
}pokemon;

//Procedimento que imprime o menu de opções
void menu()
{
    system("cls");
    printf("\t\t\tMENU\n");
    printf("\n\t1. Registrar Pokemon\n");
    printf("\t2. Listar Pokemons registrados\n");
    printf("\t3. Buscar e listar Pokemon\n");
    printf("\t4. Remover Pokemon do registro\n");
    printf("\t5. Fechar Pokedex\n");
    printf("\nDigite a opção desejada: ");
}

//Função que lista todos os pokemons registrados na Pokedex
int list_all()
{
    //Criação do ponteiro e alocação de memória para os dados que serão lidos do arquivo
    pokemon *Pokemon;
    Pokemon = malloc(sizeof(pokemon));
    //Abertura do arquivo
    FILE *fp = fopen("Pokedex.dat", "rb");
    if(!fp)
    {
        printf("Can't open file\n");
        return -1;
    }
    //lê 1 byte * tamanho da struct pokemon do arquivo "Pokedex.dat"
    //armazena na área de mémoria apontada por Pokemon e imprime os dados lidos
    while(fread(Pokemon, sizeof(pokemon), 1, fp))
    {
        printf("\nPokemon #%d: ",Pokemon->id);
        printf("\nNome: %s",Pokemon->nome);
        printf("Tipo: %s",Pokemon->tipo);
        printf("Altura: %.2f\n",Pokemon->altura);
        printf("Peso: %.2f\n",Pokemon->peso);
        printf("Attack: %d\n",Pokemon->attack);
        printf("SP Ataque: %d\n",Pokemon->SP_attack);
        printf("Defense: %d\n",Pokemon->defense);
        printf("SP Defesa: %d\n",Pokemon->SP_defense);
        printf("Velocidade: %d\n\n",Pokemon->velocidade);
        system("pause");
    }
    //Liberação da memória utilizada
    free(Pokemon);
    return 0;
}

//Função que armazena os dados dos pokemons no arquivo
int registro()
{
    //Alocação de memória para os dados que serão lidos
    pokemon *new_pokemon = malloc(sizeof(pokemon));
    if(!new_pokemon)
    {
        printf("Falha ao alocar memória\n");
        exit(1);
    }
    //Abertura do arquivo "Pokedex.dat"
    FILE *fp = fopen("Pokedex.dat", "ab");
    if(!fp)
    {
        printf("Falha ao abrir o arquivo\n");
    }
    
    //Enquanto os dados digitados não forem confirmados
    //ou caso forem digitados dados incorretos
    //é feita a releitura
    char confirmation = 'n';
    while(confirmation == 'n' || confirmation == 'N')
    {
        system("cls");
        fflush(stdin);
        printf("Nome do Pokemon: ");
        fgets(new_pokemon->nome, sizeof(new_pokemon->nome),stdin);
        printf("Tipo do Pokemon: ");
        fgets(new_pokemon->tipo, sizeof(new_pokemon->tipo),stdin);
        printf("Altura do Pokemon: ");
        scanf("%f", &new_pokemon->altura);
        printf("Peso do Pokemon: ");
        scanf("%f", &new_pokemon->peso);
        printf("Valor do atributo de Ataque: ");
        scanf("%d", &new_pokemon->attack);
        printf("Valor do atributo de SP Ataque: ");
        scanf("%d", &new_pokemon->SP_attack);
        printf("Valor do atributo de Defesa: ");
        scanf("%d", &new_pokemon->defense);
        printf("Valor do atributo de SP Defesa: ");
        scanf("%d", &new_pokemon->SP_defense);
        printf("Valor do atributo de Velocidade: ");
        scanf("%d", &new_pokemon->velocidade);
        fflush(stdin);

        //Exibe os dados digitados para verificação
        printf("Os dados digitados estão corretos?\n");
        printf("\nID: %d",new_pokemon->id);
        printf("\nNome: %s",new_pokemon->nome);
        printf("Tipo: %s",new_pokemon->tipo);
        printf("Altura: %.2f\n",new_pokemon->altura);
        printf("Peso: %.2f\n",new_pokemon->peso);
        printf("Attack: %d\n",new_pokemon->attack);
        printf("SP Ataque: %d\n",new_pokemon->SP_attack);
        printf("Defense: %d\n",new_pokemon->defense);
        printf("SP Defesa: %d\n",new_pokemon->SP_defense);
        printf("Velocidade: %d\n",new_pokemon->velocidade);
        fflush(stdin);
        printf("\nDigite \"n\" ou \"N\" para digitar os dados novamente.");
        printf("\nDigite qualquer outra tecla para confirmar o registro dos dados. ");
        scanf("%c",&confirmation);
    }

    //Testa se os dados foram escritos no arquivo
    int test = fwrite(new_pokemon, 1, sizeof(pokemon), fp);
    if(!test)
    printf("Erro ao escrever no arquivo");
    printf("Pokemon registrado.\n");
    fclose(fp);
    free(new_pokemon);
    system("pause");
    return 0;
}