install.packages("Reviews_0.1.0")

library('Reviews')
library('ggplot2')
library('dplyr')
library('tidyr')
filename = "D:\\My documents\\Study\\3\\4.txt"

vocab = get_vocab(filename)
vec_positive = count_positive(filename)
vec_negative = count_negative(filename)

#check if all 3 vectors are the same or not

length(vocab)
length(vec_negative)
length(vec_positive)

#check the beginning of the vocabulary

head(vocab, 300)
tail(vocab, 300)

#cut all the numbers and blanks
vocab.s = vocab[-c(1:254)]
vec_negative.s = vec_negative[-c(1:254)]
vec_positive.s = vec_positive[-c(1:254)]

#check again
length(vocab.s)
length(vec_negative.s)
length(vec_positive.s)

# plots

ggplot(data = as.data.frame(vec_negative.s), aes(vec_negative.s)) +
      geom_histogram( fill = "tomato", alpha = 0.5) +
      scale_x_log10() +
      scale_y_log10() +
      geom_vline(aes(xintercept=median(vec_positive, na.rm=T)),   # Ignore NA values for mean
             color="red", linetype="dashed", size=1)+
      ggtitle( "Negative words in IMDB review") +
      labs(x ="Number of appearances" , y ="Number of words") +
      theme_minimal()



ggplot(data = as.data.frame(vec_positive.s), aes(vec_positive.s)) +
      geom_histogram( fill = "steelblue", alpha = 0.5) +
      scale_x_log10() +
      scale_y_log10() +
      geom_vline(aes(xintercept=median(vec_positive, na.rm=T)),   # Ignore NA values for mean
             color="darkblue", linetype="dashed", size=1)+
      theme_minimal() +
      ggtitle( "Positive words in IMDB review") +
      labs(x ="Number of appearances" , y ="Number of words")
##########
df <- data.frame(vocab.s, vec_negative.s, vec_positive.s)

ggplot(subset(df, vec_negative.s> 400), aes( vocab.s, vec_negative.s)) + geom_bar(stat = "identity")


ggplot(subset(df, vec_positive.s> 400), aes( vocab.s, vec_positive.s)) + geom_bar(stat = "identity")

##Two-sample Kolmogorov-Smirnov test
ks.test(vec_negative, vec_positive, alternative = "two.sided", exact = NULL)

#####5 most poppular words

top5_positive <-  sort(vec_positive.s,T)[1:5]
top5_negative <-  sort(vec_negative.s,T)[1:5]

(top5_words_positive <- vocab.s[vec_negative.s %in% top5_negative])
(top5_words_positive <- vocab.s[vec_negative.s %in% top5_negative])

df <- data_frame(vocab.s[vec_negative.s %in% top5_negative], top5_positive, top5_negative)

names(df) <- c("Words", "Negative", "Positive")

df <- df %>% gather(Sentiments, Frequency, -Words)


ggplot(df, aes(x = Words, y = Frequency, fill = Sentiments)) + 
  geom_bar(stat = "identity", position =  "dodge")+
  geom_text(aes(label = Frequency), size = 3,  position = position_dodge(width = 1) )

vocab[(vec_negative==vec_positive+max(vec_negative- vec_positive))]

vocab[(vec_positive==vec_negative+max(vec_positive- vec_negative))]
