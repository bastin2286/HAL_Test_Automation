pipeline 
{
    agent none
    stages 
    {
        stage('SCM Poll') 
        {
            agent any
            steps 
            {  	
				sh '''ls -la'''
				sh '''pwd'''
				sh '''ssh \'318356@10.10.196.130\' docker volume create volHALRobot'''
				
               echo "********Waiting for SCM event - IN PROGRESS***********"
                /*
				script 
				{
				    properties([pipelineTriggers([pollSCM('* * * * *')])])
				}
				echo "Waiting for SCM event - Done"
				git branch: 'master', credentialsId: 'nandu', url: 'https://github.com/nandunarayanan/Android_Demo.git'
				*/
				
				/*
				
				checkout([$class: 'GitSCM', 
				branches: [[name: "origin/master"]], 
				userRemoteConfigs: [[
                url: 'https://github.com/nandunarayanan/Android_Demo.git']]
				])
				*/
				echo "Testing for SCM event - Done"
				echo "************copying the git update to the volume- IN PROGRESS***********"
				sh '''ssh \'318356@10.10.196.130\' /home/hal_util_scripts/copy.sh'''
				echo  "************copying the git update to the volume - DONE ****************"
				sh '''ls -la'''
				sh '''pwd'''
				
            }
        }
        
        stage('Deployment to DUT from Host Server') 
	{
            agent any
            steps  
            {
		 sh '''ssh \'318356@10.10.196.130\' docker pull localhost:5000/haldeploy:v2'''   
                 sh '''ssh \'318356@10.10.196.130\' docker run --name halDeploy -p 30180:30180 -v volHAL:/src localhost:5000/haldeploy:v2'''
            }
        }
	    
	stage('Execute test in DUT from Host') 
	{
            agent any
            steps  
            {
                 sh '''ssh \'318356@10.10.196.130\' docker pull localhost:5000/haltestbuild:v1'''   
                 sh '''ssh \'318356@10.10.196.130\' docker run --name halBuild -p 30180:30180 -v volHAL:/src localhost:5000/haltestbuild:v1'''
            }
        }
         stage('Declarative Post Actions') 
	{
            agent any
            steps  
            {
               sh '''ssh \'318356@10.10.196.130\' /home/hal_util_scripts/copy_xml.sh'''
	       robot archiveDirName: 'robot-plugin', outputPath: '', overwriteXAxisLabel: ''
		sh '''ssh \'318356@10.10.196.130\' docker stop halDeploy'''
		sh '''ssh \'318356@10.10.196.130\' docker rm halDeploy'''
		sh '''ssh \'318356@10.10.196.130\' docker stop halBuild'''
		sh '''ssh \'318356@10.10.196.130\' docker rm halBuild'''
            }
        }
    }
}
