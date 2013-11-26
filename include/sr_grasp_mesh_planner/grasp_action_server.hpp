#pragma once

//-------------------------------------------------------------------------------

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <VirtualRobot/Visualization/TriMeshModel.h>
#include <sr_grasp_msgs/GraspMeshAction.h>

#include "sr_grasp_mesh_planner/grasp_planner_window.hpp"

//-------------------------------------------------------------------------------

using namespace VirtualRobot;

//-------------------------------------------------------------------------------

class GraspActionServer
{
protected:
  ros::NodeHandle nh_;
  // NodeHandle instance must be created before this line. Otherwise strange error may occur.

  // Auto start the action server?
  static const bool auto_start_;

  std::string action_name_;

  actionlib::SimpleActionServer<sr_grasp_msgs::GraspMeshAction> as_mesh_;
  boost::shared_ptr<sr_grasp_msgs::GraspMeshFeedback> feedback_mesh_;
  boost::shared_ptr<sr_grasp_msgs::GraspMeshResult> result_mesh_;

  boost::shared_ptr<GraspPlannerWindow> grasp_win_;

public:
  // This constructor uses actionlib!
  // Note that node_name is used as the action name.
  GraspActionServer(std::string node_name,
                    boost::shared_ptr<GraspPlannerWindow> grasp_win);

  virtual ~GraspActionServer();

private:
  void goal_cb_mesh(const sr_grasp_msgs::GraspMeshGoalConstPtr &goal);
};

//-------------------------------------------------------------------------------
