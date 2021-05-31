mu = 0.4;
lambda = 0.3;
t = 6;

f = @(z) exp(-mu / lambda ./ z) .* exp(mu / lambda .* (z - (z - 1) .* exp(lambda * t)) ./ z) .* z ./ (z - (z - 1) .* exp(lambda * t));
g = @(u) f(exp(1i .* u));
h = @(w) 1 / sqrt(2 * pi) .* real(integral(@(u) g(u) .* exp(1i .* u .* w), -pi, pi, "ArrayValued", true));

x = 0 : 1 : 10;
y = h(x)
sum(y)
plot(x, y);