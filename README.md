# PHSX815_Project3
## Introduction
This project contains two independent programs. The first program **``getDecay.C``** is simulating the data based on the true value of a param
eter. This parameter spacifies the probabilities for the outcomes in a single trial. We put the true value for the parameter as **0.44**, which is also the probability of detecting beta particle in the detector in a single decay. <br />
The second program **``ParamEstimation.C``** analyse the data and estimates a value for the unknown paramter. What it usuallyd do is, it writes an expression for the log-likelihood ratio(LLR) for the the probability distribution ([categorical distribution](https://en.wikipedia.org/wiki/Categorical_distribution))



$${L(x|\theta) = &prod;_{i=1}^k p_i^{(x=i)}}$$ <br>

The maximization of the LLR gives an estimated value for the unknown parameter. This can be done by using the Lagrange multiplier methods while considering the one constraint equation, that is given by the conservation of the probability. So this method return the expression to estimate the theta as <br>
$${\theta = \frac{ \sum {\beta} }{N} }$$

## How to run the programs?
