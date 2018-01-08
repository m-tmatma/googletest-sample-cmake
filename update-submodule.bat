cd /d %~dp0

git submodule init
git submodule update
git submodule foreach git reset --hard
git submodule foreach git checkout master
git submodule foreach git pull origin master

