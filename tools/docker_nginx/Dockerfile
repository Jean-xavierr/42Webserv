FROM	nginx

RUN		apt update

RUN		apt install -y	\
		vim	curl zsh

# Install CGI requirements
RUN		apt install -y	\
		php7.3			\
		php7.3-fpm

COPY	./www /tmp/www

RUN		chown nginx /tmp/www

COPY temp.conf /etc/nginx/conf.d/default.conf
