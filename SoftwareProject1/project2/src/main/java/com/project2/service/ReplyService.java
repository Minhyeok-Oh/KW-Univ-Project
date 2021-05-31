package com.project2.service;

import java.util.List;

import com.project2.domain.BoardVO;
import com.project2.domain.ReplyVO;

public interface ReplyService {

	// comment list
	public List<ReplyVO> readReply(int bno) throws Exception;

	// the number of comment counting
	public int countReply(int bno) throws Exception;

	// write comment
	public void writeReply(ReplyVO vo) throws Exception;

	// view comment for comment number
	public ReplyVO viewReply(int rno) throws Exception;

	// delete comment
	public void deleteReply(int rno) throws Exception;
}
