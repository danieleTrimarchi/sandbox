clear all

x0=linspace(-0.03,0.03,100); 

% translate x
x = x0 - min(x0); 

% compute logx
ylog= log(x);

% forget first value
x = x(2:size(x,2));
ylog = ylog(2:size(ylog,2));

hold off
figure(1)
plot(x,x);
hold on
plot(x,ylog);

% Now vertically translate ylog
ylogPositive = ylog - min(ylog)

plot(x,ylogPositive);

% compute the first derivative of the log @start
yprime = (ylog(2) - ylog(1)) / (x(2)-x(1)); 

% set a compression factor
compress = 100; 

xscaled = (x - x(1))* yprime / compress;
ylogpositivescaled = ylogPositive / compress; 

figure(2)
plot(x,x,'+');
hold on
plot(xscaled,ylogpositivescaled,'--');
plot(x,sqrt(x),'o')
xlim([0 0.06])
legend('y=x','translated log','sqrt')
ylim([0 0.06])