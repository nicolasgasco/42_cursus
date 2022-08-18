NAME = cub3D
FLAGS = -Wall -Wextra -Werror -Wno-unused-result
SANITIZE = -g3 -fsanitize=address
VALGRIND = -g -Og -std=gnu99
INC = -I%.h -I$(LIB_DIR)%.h -I/usr/include -Imlx_linux -O3
MINILIB_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC_NAME =	cub3d.c\
		scene_desc_file_validation/ft_scene_desc_file_validation.c\
		scene_desc_file_validation/ft_type_ids_validation.c\
		scene_desc_file_validation/ft_type_ids_validation-orientation.c\
		scene_desc_file_validation/ft_type_ids_validation-orientation_utils.c\
		scene_desc_file_validation/ft_type_ids_validation-colors.c\
		scene_desc_file_validation/ft_type_ids_validation-colors_utils.c\
		scene_desc_file_validation/ft_type_ids_validation-completeness.c\
		scene_desc_file_validation/ft_map_content_validation.c\
		scene_desc_file_validation/ft_map_content_validation-map_size.c\
		scene_desc_file_validation/ft_map_content_validation-allowed_chars.c\
		scene_desc_file_validation/ft_map_content_validation-map_walls.c\
		scene_desc_file_validation/ft_map_content_validation-map_content.c\
		scene_desc_file_validation/ft_type_ids_validation-errors_0.c\
		scene_desc_file_validation/ft_type_ids_validation-errors_1.c\
		post_validation_data_manip/ft_map_data_manip.c\
		post_validation_data_manip/ft_map_data_manip-fc_colors.c\
		post_validation_data_manip/ft_map_data_manip-asset_sizes.c\
		post_validation_data_manip/ft_map_data_manip-color_codes_0.c\
		post_validation_data_manip/ft_map_data_manip-color_codes_1.c\
		post_validation_data_manip/ft_map_data_manip-char_map.c\
		post_validation_data_manip/ft_map_data_manip-asset_validation.c\
		post_validation_data_manip/ft_map_data_manip-errors.c\
		post_validation_data_manip/ft_map_data_manip-texture_files.c\
		post_validation_data_manip/ft_map_data_manip-asset_sizes_validation.c\
		render_window/ft_render_view.c\
		render_window/ft_render_scene.c\
		render_window/ft_render_scene-texture.c\
		render_window/ft_scene_events.c\
		render_window/ft_scene_movements-linear.c\
		render_window/ft_scene_movements-rotation.c\
		render_window/ft_scene_movements-utils.c\
		render_window/ft_scene_events-keyboard.c\
		render_window/ft_scene_movements-collisions.c\
		raycasting_calculation/ft_raycasting_calculation.c\
		raycasting_calculation/ft_trigonometric_table.c\
		raycasting_calculation/ft_increment_table.c\
		utils/get_next_line.c\
		utils/ft_utils_0.c\
		utils/ft_utils_1.c\
		utils/ft_map_utils.c\
		utils/ft_map_content_utils.c\
		utils/ft_common_errs.c\
		utils/ft_free_0.c\
		utils/ft_free_1.c\
		utils/ft_debug.c\
		utils/ft_raycast_utils.c\
		utils/ft_raycast_utils1.c\
		utils/ft_render_utils.c\

SRC_NAME_BONUS =	cub3d_bonus.c\
		scene_desc_file_validation/ft_scene_desc_file_validation_bonus.c\
		scene_desc_file_validation/ft_type_ids_validation_bonus.c\
		scene_desc_file_validation/ft_type_ids_validation-orientation_bonus.c\
		scene_desc_file_validation/ft_type_ids_validation-orientation_utils_bonus.c\
		scene_desc_file_validation/ft_type_ids_validation-colors_bonus.c\
		scene_desc_file_validation/ft_type_ids_validation-colors_utils_bonus.c\
		scene_desc_file_validation/ft_type_ids_validation-completeness_bonus.c\
		scene_desc_file_validation/ft_map_content_validation_bonus.c\
		scene_desc_file_validation/ft_map_content_validation-map_size_bonus.c\
		scene_desc_file_validation/ft_map_content_validation-allowed_chars_bonus.c\
		scene_desc_file_validation/ft_map_content_validation-map_walls_bonus.c\
		scene_desc_file_validation/ft_map_content_validation-map_content_bonus.c\
		scene_desc_file_validation/ft_type_ids_validation-errors_0_bonus.c\
		scene_desc_file_validation/ft_type_ids_validation-errors_1_bonus.c\
		post_validation_data_manip/ft_map_data_manip_bonus.c\
		post_validation_data_manip/ft_map_data_manip-fc_colors_bonus.c\
		post_validation_data_manip/ft_map_data_manip-asset_sizes_bonus.c\
		post_validation_data_manip/ft_map_data_manip-color_codes_0_bonus.c\
		post_validation_data_manip/ft_map_data_manip-color_codes_1_bonus.c\
		post_validation_data_manip/ft_map_data_manip-char_map_bonus.c\
		post_validation_data_manip/ft_map_data_manip-asset_validation_bonus.c\
		post_validation_data_manip/ft_map_data_manip-errors_bonus.c\
		post_validation_data_manip/ft_map_data_manip-texture_files_bonus.c\
		post_validation_data_manip/ft_map_data_manip-asset_sizes_validation_bonus.c\
		render_window/ft_render_view_bonus.c\
		render_window/ft_render_scene_bonus.c\
		render_window/ft_render_scene-texture_bonus.c\
		render_window/ft_scene_events_bonus.c\
		render_window/ft_scene_movements-linear_bonus.c\
		render_window/ft_scene_movements-rotation_bonus.c\
		render_window/ft_scene_movements-utils_bonus.c\
		render_window/ft_scene_events-keyboard_bonus.c\
		render_window/ft_scene_movements-collisions_bonus.c\
		render_window/ft_scene_movements-mouse-rotation_bonus.c\
		raycasting_calculation/ft_raycasting_calculation_bonus.c\
		raycasting_calculation/ft_trigonometric_table_bonus.c\
		raycasting_calculation/ft_increment_table_bonus.c\
		utils/get_next_line_bonus.c\
		utils/ft_utils_0_bonus.c\
		utils/ft_utils_1_bonus.c\
		utils/ft_map_utils_bonus.c\
		utils/ft_map_content_utils_bonus.c\
		utils/ft_common_errs_bonus.c\
		utils/ft_free_0_bonus.c\
		utils/ft_free_1_bonus.c\
		utils/ft_debug_bonus.c\
		utils/ft_raycast_utils_bonus.c\
		utils/ft_raycast_utils1_bonus.c\
		utils/ft_render_utils_bonus.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

OBJ_NAME_BONUS = $(SRC_NAME_BONUS:.c=.o)
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS),$(OBJ_NAME_BONUS))

LIB_DIR = ./Libft/
SRC_DIR = ./src/
SRC_DIR_BONUS = ./bonus/
SCN_DIR = scene_desc_file_validation/
RCC_DIR = raycasting_calculation/
WIN_DIR = render_window/
DATA_MANIP_DIR = post_validation_data_manip/
UTL_DIR = utils/
OBJ_DIR = ./obj/
OBJ_DIR_BONUS = ./obj_bonus/
MLX_DIR = ./mlx/
MLX_LINUX_DIR = ./mlx_linux/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@make -C $(MLX_DIR) --silent
	@gcc $(FLAGS) $(SANITIZE) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft $(MINILIB_MAC)
	@echo "##### cub3d compiling finished! #####"

bonus: $(OBJ_BONUS)
	@make -C $(LIB_DIR) --silent
	@make -C $(MLX_DIR) --silent
	@gcc $(FLAGS) $(SANITIZE) -o $(NAME)_bonus $(OBJ_BONUS) -L $(LIB_DIR) -lft $(MINILIB_MAC)
	@echo "##### cub3d bonus compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)$(SCN_DIR)
	@mkdir -p $(OBJ_DIR)$(DATA_MANIP_DIR)
	@mkdir -p $(OBJ_DIR)$(UTL_DIR)
	@mkdir -p $(OBJ_DIR)$(RCC_DIR)
	@mkdir -p $(OBJ_DIR)$(WIN_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) $(SANITIZE) -o $@ -c $< $(INC)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(OBJ_DIR_BONUS)$(SCN_DIR)
	@mkdir -p $(OBJ_DIR_BONUS)$(DATA_MANIP_DIR)
	@mkdir -p $(OBJ_DIR_BONUS)$(UTL_DIR)
	@mkdir -p $(OBJ_DIR_BONUS)$(RCC_DIR)
	@mkdir -p $(OBJ_DIR_BONUS)$(WIN_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) $(SANITIZE) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(NAME)
	@echo "##### Removed binary files #####"

re: fclean all

clean_bonus:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(OBJ_BONUS)
	@rm -rf $(OBJ_DIR_BONUS)
	@echo "##### Removed object files #####"

fclean_bonus: clean_bonus
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(NAME)_bonus
	@echo "##### Removed binary files #####"

re_bonus: fclean_bonus bonus

test_validation:
	@make re > /dev/null 2> /dev/null
	@sh tests/validation_tests.sh

.PHONY: all clean fclean re test bonus