service mysql start

# Confiugration de l'acces aux fichiers web
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

# Creation du fichier testcom
mkdir /var/www/testcom && touch /var/www/testcom/index.php
echo "Coucou <?php phpinfo(); ?>" >> /var/www/testcom/index.php

# SSL
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/testcom.pem -keyout /etc/nginx/ssl/testcom.key -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=vronchin/CN=testcom"

# Configuration de  NGINX: lien symbolique dans le enabled en retirant le default
mv ./tmp/nginx-conf /etc/nginx/sites-available/testcom
ln -s /etc/nginx/sites-available/testcom /etc/nginx/sites-enabled/testcom
rm -rf /etc/nginx/sites-enabled/default

# Configuration de  MYSQL
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

# Téléchargement de  PHPmyadmin
mkdir /var/www/testcom/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
tar -xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz --strip-components 1 -C /var/www/testcom/phpmyadmin
mv ./tmp/phpmyadmin.inc.php /var/www/testcom/phpmyadmin/config.inc.php

# Téléchargement de Wordpress
cd /tmp/
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/ /var/www/testcom
mv /tmp/wp-config.php /var/www/testcom/wordpress

service php7.3-fpm start
service nginx start
bash
