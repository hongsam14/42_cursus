#openssl
echo "ssl request..."

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Hong/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
chmod 600 localhost.dev.*
mv localhost.dev.key /etc/ssl/private/
mv localhost.dev.crt /etc/ssl/certs/

#nginx
echo " current environment variable:AUTOINDEX = $AUTOINDEX..."

bash autoindex.sh
mv ./default /etc/nginx/sites-available/
cat /etc/nginx/sites-available/default
ln -s etc/nginx/sites-available/default etc/nginx/sites-enabled

service nginx start
service php7.3-fpm start

#make user in mysql
echo " Create mysql user..."

service mysql start
echo "ID : suhong PW : 2486"
echo "CREATE USER 'suhong'@'localhost' IDENTIFIED BY '2486';" | mysql -u root --skip-password

#phpmyadmin
tar -xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpmyadmin
mv config.inc.php /var/www/html/phpmyadmin/
mkdir /var/www/html/phpmyadmin/tmp
chmod 777 /var/www/html/phpmyadmin/tmp

mysql < /var/www/html/phpmyadmin/sql/create_tables.sql

#wordpress
tar -xvf latest.tar.gz
mv wordpress /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
mv wp-config.php /var/www/html/wordpress/

echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password

#user privileges setting

echo "GRANT ALL PRIVILEGES ON *.* to 'suhong'@'localhost';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES" | mysql -u root --skip-password

#start
service nginx reload
service php7.3-fpm reload
service mysql reload
tail -f /dev/null
