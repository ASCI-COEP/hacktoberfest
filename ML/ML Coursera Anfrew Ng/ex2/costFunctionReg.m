function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta
h=sigmoid(X*theta);
J= (1/m)*(-y'*log(h)-(1-y)'*log(1-h)) + (lambda/(2*m))*(sum(theta.^2)-theta(1,1)^2);
%J(1,1)=J(1,1)-(lambda/(2*m))*(theta(1,1)^2);
 %s= (X*theta-y)'*X;
 
 grad=(1/m)*(X)' * (h-y) + (lambda/m)*(theta) ;
 %grad(1,1)=sum((1/m) * (sigmoid(X(1,:)*theta)-y(1,:))*(X(1,:)));
  grad(1,1)=grad(1,1)-(lambda/m)*(theta(1,1));




% =============================================================

end
