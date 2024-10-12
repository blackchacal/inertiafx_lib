/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \brief Main project configuration file.                                    *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 6th 2024                                                    *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

/* Project version is defined in CMakeLists.txt */
#define InertiaFX_VERSION_MAJOR @InertiaFX_VERSION_MAJOR@
#define InertiaFX_VERSION_MINOR @InertiaFX_VERSION_MINOR@
#define InertiaFX_VERSION_PATCH @InertiaFX_VERSION_PATCH@

/****************************************************************************** 
 * Logger Configurations                                                      *
 ******************************************************************************/

#define LOGGER_EN   (1)
#define LOGGER_MAX_LOG_MSG_SIZE (256)
#define LOGGER_LOG_FILENAME ("@PROJECT_BINARY_DIR@/inertiafx.log")
#define LOGGER_LOG_TO_CONSOLE   (1)
#define LOGGER_LOG_TO_FILE      (1)