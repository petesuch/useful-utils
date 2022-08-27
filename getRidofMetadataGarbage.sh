## getRidofMetadataGarbage.sh

##  Netbeans and Eclipse leave behind a lot of junk. This is an attempt to tidy
##  up and remove everything but the src files

find . -type f -name *.class -delete
find . -type f -name .metadata -delete
find . -type d -name .metadata exec rm -rv {} +
find . -type d -name *.metadata -exec rm -rv {} +
find . -type f -name *.stackdump -delete
find . -type d -name .git -exec rm -rv {} +
find . -type f -name *.swp -delete
find . -type f -name *.pyc -delete
find . -type d -name .project -exec rm -rv {} +
find . -type d -name .project
find . -type d -name .py*
find . -type d -name .classpath -exec rm -rv {} +;
find . -type d -name .settings -exec rm -rv {} +
find . -type f -name .classpath -exec rm -rv {} +
find . -type f -name .tlog -exec rm -rv {} +
find . -type f -name *.tlog -exec rm -rv {} +
find . -type f -name .classpath -exec rm -rv {} +
find . -type f -name *.cache -exec rm -rv {} +
find . -type d -name .recommenders -exec rm -rv {} +
find . -type f -name *.project -exec rm -rv {} +
find . -type d -name *__pycache__ -delete
find . -type d -name *__pycache__ -exec rm -rv {} +
