install.packages("xlsx", dep = T)
install.packages("readxl")
library("xlsx")
library("readxl")
library("dplyr")


excel_sheets("katalog.xlsx")
excel_sheets("vidacha.xlsx")
excel_sheets("chit.xlsx")
excel_sheets("exemp.xlsx")

chit <- read_xlsx("katalog.xlsx", sheet="Каталог_1")

vidacha <-read_xlsx("vidacha.xlsx", sheet="Выдача_1")

chit1 <- read_xlsx("chit.xlsx", sheet="Лист1")

exemp <- read_xlsx("exemp.xlsx", sheet="Фонд_1")




######ТУТ ВЫВОД ВСЕХ НААПИСАНЫХ КНИГ
  
k <- c()

if ( is.na(chit$p100a[i])){
  next
}


for (i in 1:100000) {
  
 
  if ( is.na(chit$p100a[i])){
    next
  }
  
  if ( chit$p100a[i] == "Устинова Татьяна Витальевна")
  {

    k[i] <- chit$p245a[i]
  }

  
  
  } 


bad<-is.na(k)
k <- k[!bad]
k1 <- as.vector(k)


####ОСНОВНОЙ АЛГОРИТМ
### выбор прочитаных книг


k <- c()

for (i in 1:length(vidacha$`ИД читателя`)) {
  
  if (vidacha$`ИД читателя`[i] == "232")
  {
    k[i] <- vidacha$`Штрих-код`[i]
  }
  
}


###Получаем РАЗДЕЛ ЗНАНИЙ последних прочитаных книг

n <- 0
i <- 1
while(n == 0 & i < length(exemp$`Штрих-код`) ) {
    
  i=i+1

  if (exemp$`Штрих-код`[i] == k[length(k)])
  {
    n <- exemp$`Раздел знаний`[i]
  }
}


###А тут выдает рекомендацию)))
rek <- 0
i <- 1
while( rek == 0) {
  
  i=i+1
  
  if ( is.na(chit$p084a[i])){
    next
  }
  
  if (i == length(chit$p084a))
  {
    break
  }
  
  
  if (chit$p084a[i] == n) {
    rek <- c(chit$p245a[i],chit$p100a[i])
  }
  
}



###А тут выдает ТРИ-Четыре РЕКОМЕНДАЦИИ)))

rek <- 0
i <- 1
for (i in 1:length(chit$p084a)) {

  
  if ( is.na(chit$p084a[i])){
    next
  }
  
  if (12 < length(rek))
  {
    break
  }
  
  
  if (chit$p084a[i] == n) {
    rek <- append(c(chit$p245a[i],chit$p100a[i]),rek)
  }
  
}



